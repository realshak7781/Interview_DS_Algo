// BFS BASED APPROACH :
// TIME COMPLEXTIY  :  O(10*10*n**2*N)
// SPACE COMPLEXITY :  O(10*10*n)
class Solution {
string addA(string s,int a){

    for(int i=1;i<s.length();i+=2){
        int val=s[i]-'0';
        int newVal=(val+a)%10;
        s[i]=(char)(newVal + '0');
    }
    return s;
}

string rotate(string &s,int b){

    int endIdx=s.length()-b;
    string lastPart=s.substr(endIdx);
    string startPart=s.substr(0,endIdx);

    string res=lastPart+startPart;
    return res;
}
public:
    string findLexSmallestString(string s, int a, int b) {
        string res=s;
        queue<string> q;
        q.push(s);
        unordered_set<string> vis;
        vis.insert(s);


        while(!q.empty()){
            int size=q.size();

            for(int i=0;i<size;i++){
                string top=q.front();
                q.pop();

                if(top<res)res=top;

                string add=addA(top,a);
                string rot=rotate(top,b);

                if(!vis.count(add)){
                    q.push(add);
                    vis.insert(add);
                }

                
                if(!vis.count(rot)){
                    q.push(rot);
                    vis.insert(rot);
                }
            }
        }

        return res;
    }
};


// THOUGHT OF THE GREEDY APPROACH : BUT FAILED SO TRIED TO WORK WITH TRYING OUT ALL POSSIBILITIES INSTEAD OF CHOOSING THE OPTIMAL AT EACH LEVEL : INTUITION FOR BFS THERE IS A SOURCE AND CONDITION AND LEVELS 
class Solution {
string addA(string s,int a){

    for(int i=1;i<s.length();i+=2){
        int val=s[i]-'0';
        int newVal=(val+a)%10;
        s[i]=(char)(newVal + '0');
    }
    return s;
}

string rotate(string &s,int b){

    int endIdx=s.length()-b;
    string lastPart=s.substr(endIdx);
    string startPart=s.substr(0,endIdx);

    string res=lastPart+startPart;
    return res;
}
public:
    string findLexSmallestString(string s, int a, int b) {

       
       while(true){
         string add=addA(s,a);
         string rot=rotate(s,b);
         string org=s;

         if(add<s){
            s=add;
         }

         if(rot<s){
            s=rot;
         }

         if(s==org) return s;
       }

       return "";
    }
};
