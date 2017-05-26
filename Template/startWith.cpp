bool startWith(string n,string m){
    if(n.size() < m.size())
        return false;
    else{
        for(int i = 0;i < m.size();i++)
            if(n[i] != m[i])
                return false;
        return true;
    }
}
