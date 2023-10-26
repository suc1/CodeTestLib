namespace std {
    template <>
    struct hash<tuple<int, int>> {
        size_t operator()(const tuple<int, int>& t) const {
            return hash<int>()(get<0>(t)) ^ hash<int>()(get<1>(t));
        }
    };
}

class Solution {    //Fail: test 25
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int curX=0, curY=0;
        int dir=1; //0=+x, 1=+y, 2=-x; 3=-y
        int maxX=0, maxY=0;

        unordered_set< tuple<int, int> > mySet;   //tuple has no hash function
        //unordered_set< vector<int> > mySet;       //vector has no hash function
        for(auto i: obstacles) {
            mySet.insert( make_tuple(i[0], i[1]) );
        }

        for(int c:commands) {
            switch(c) {
                case -2:
                    ++dir;
                    dir %= 4;
                    break;
                case -1:
                    --dir;
                    if(dir<0) dir+=4;
                    dir %= 4;
                    break;
                default:
                    for(int i=0; i<c; ++i) {
                        int newX=curX, newY=curY;
                        switch(dir) {
                            case 0:
                                ++newX;
                                break;
                            case 1:
                                ++newY;
                                break;
                            case 2:
                                --newX;
                                break;
                            case 3:
                                --newY;
                                break;
                        }
                        if(mySet.find( make_tuple(newX, newY) )!=mySet.end()) break;
                        curX = newX;
                        curY = newY;

                        maxX = max(maxX, abs(curX));
                        maxY = max(maxY, abs(curY));                        
                    }
            }
        } 

        return maxX * maxX + maxY * maxY;
    }
};