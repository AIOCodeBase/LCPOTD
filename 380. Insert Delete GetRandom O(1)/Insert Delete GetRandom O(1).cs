public class RandomizedSet {
    
    private Dictionary<int,int> cache; 
    private Random rnd;
    private List<int> data;
    public RandomizedSet() {
        cache = new Dictionary<int,int>();
        rnd = new Random();
        data = new List<int>();
    }
    
    public bool Insert(int val) {
        if(cache.ContainsKey(val))
            return false;
        else
        {
            data.Add(val);
            cache.Add(val,(data.Count-1));
            return true;
        }
    }
    
    public bool Remove(int val) {
          if(!cache.ContainsKey(val))
            return false;
        else
        {
            int lastIndex = (data.Count-1);
            int lastElem = data[lastIndex];
            
            int i = cache[val];
            data[i] = lastElem;
            cache[lastElem] = i;
            
            data.RemoveAt(lastIndex);
            cache.Remove(val);
            
            return true;
        }
            
    }
    
    public int GetRandom() {
        Console.WriteLine(cache.Count);
        return data[rnd.Next(data.Count)];
    }
}