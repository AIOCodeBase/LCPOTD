#define LIST_SIZE  128

typedef struct
{
    int val;
    struct MyNode* next;
} MyNode;

typedef struct {
    MyNode** lists;
    int* counts;
    int total;
} RandomizedSet;


RandomizedSet* randomizedSetCreate() {
    RandomizedSet* obj = (RandomizedSet*)malloc(sizeof(RandomizedSet));
    
    obj->lists = (MyNode**)calloc(LIST_SIZE,sizeof(MyNode*));
    obj->counts = (int*)calloc(LIST_SIZE,sizeof(int));
    obj->total = 0;
    
    return obj;
}

bool randomizedSetInsert(RandomizedSet* obj, int val) {
    int key = abs(val)%LIST_SIZE;
    MyNode* newNode = NULL;
    MyNode* tempNode = NULL;
    MyNode* preNode = NULL;
    
    if(obj->lists[key] == NULL)
    {
        newNode = (MyNode*)malloc(sizeof(MyNode));
        newNode->val = val;
        newNode->next = NULL;
        
        obj->lists[key] = newNode;
    }
    else
    {
        tempNode = obj->lists[key];
        while(tempNode)
        {
            preNode = tempNode;
            if(tempNode->val == val)
                return false;
            tempNode = tempNode->next;
        }
        if(tempNode == NULL)
        {
            newNode = (MyNode*)malloc(sizeof(MyNode));
            newNode->val = val;
            newNode->next = NULL;
            
            preNode->next = newNode;
        }
    }
    
    obj->counts[key]++;
    obj->total++;
    return true;
}

bool randomizedSetRemove(RandomizedSet* obj, int val) {
    MyNode* preNode = NULL;
    MyNode* tempNode = NULL;
    int key = abs(val)%LIST_SIZE;
    
    if(obj->lists[key] == NULL)
    {
        return false;
    }
    else
    {
        tempNode = obj->lists[key];
        while(tempNode)
        {
            if(tempNode->val == val)
            {
                if(preNode)
                {
                    preNode->next = tempNode->next;
                }
                else
                {
                    obj->lists[key] = tempNode->next;
                }
                free(tempNode);
                obj->counts[key]--;
                obj->total--;
                return true;
            }
            preNode = tempNode;
            tempNode = tempNode->next;
        }
        return false;
    }
}

/** Get a random element from the set. */
int randomizedSetGetRandom(RandomizedSet* obj) {
    int pos = rand()%obj->total;
    int i,sum = 0, key = 0;
    MyNode* tempNode = NULL;
    
    for(i=0;i<LIST_SIZE;i++)
    {
        if(pos >= obj->counts[i])
        {
            pos -= obj->counts[i];
        }
        else
        {
            key = i;
            break;
        }
    }
    
    tempNode = obj->lists[key];
    while(tempNode && pos)
    {
        tempNode = tempNode->next;
        pos--;
    }
    
    return tempNode->val;
}

void randomizedSetFree(RandomizedSet* obj) {
    int i;
    MyNode* preNode = NULL;
    MyNode* tempNode = NULL;
    
    for(i=0;i<LIST_SIZE;i++)
    {
        tempNode = obj->lists[i];
        while(tempNode)
        {
            preNode = tempNode;
            tempNode = tempNode->next;
            free(preNode);
        }
    }
    free(obj->counts);
    free(obj);
}