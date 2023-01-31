class RandomizedSet {
    constructor() {
        this.valMap = new Map(),
        this.indexMap = new Map();
        
        this.highest = -1;
    }
    
    insert(val) {
        if(this.valMap.has(val)) return false;
        
        this.highest += 1;
        this.valMap.set(val, this.highest);
        this.indexMap.set(this.highest, val);
        
        return true;
    }
    
    remove(val) {
        if(!this.valMap.has(val)) return false;
        
        const currIdx = this.valMap.get(val);
        const valAtLastIdx = this.indexMap.get(this.highest);
        this.indexMap.set(currIdx, valAtLastIdx); 
        this.valMap.set(valAtLastIdx, currIdx);
        this.valMap.delete(val);
        this.indexMap.delete(this.highest);
        
        this.highest -= 1;
        
        return true;
    }
    
    getRandom() {
        if(this.highest < 0) return null;
        
        const rnd = this.generateRandom();
        return this.indexMap.get(rnd);
    }
    
    generateRandom() {
        return Math.floor(Math.random() * (this.highest + 1));
    }
}