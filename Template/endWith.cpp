bool endWith(string n, string m){
    if(n.size() < m.size())
        return false;
    else{
        for(int i = 1; i <= m.size(); i++)
            if(n[n.size() - i] != m[m.size() - i])
                return false;
        return true;
    }
}
