bool startWith(string n,string m){
    if(n.size() < m.size())
        return false;
    else{
        for(int i = m.size() - 1;i >= 0;i--)
            if(n[i] != m[i])
                return false;
        return true;
    }
}
