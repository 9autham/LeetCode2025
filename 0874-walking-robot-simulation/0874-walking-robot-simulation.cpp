class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>>s;
        for(int i=0;i<obstacles.size();i++)
        {
            s.insert({obstacles[i][0],obstacles[i][1]});
        }
        int maxi=0;
        int maxi_x=0,maxi_y=0;
        int x=0,y=0;
        bool north=true,south=false,east=false,west=false;
        for(int i=0;i<commands.size();i++)
        {
            if(commands[i]==-2)
            {
              if(north==true)
              {
              west=true;
              north=false,south=false,east=false;
              continue;
              }
              if(west==true)
              {
              south=true;
              north=false,east=false,west=false;
              continue;
              }
              if(south==true)
              {
              east=true;
              north=false,south=false,west=false;
              continue;
              }
              if(east==true)
              {
              north=true;
              south=false,east=false,west=false;
              continue;
              }
            }

            if(commands[i]==-1)
            {
              if(north==true)
              {
              east=true;
              north=false,south=false,west=false;
              continue;
              }
              if(west==true)
              {
              north=true;
              south=false,east=false,west=false;
              continue;
              }
              if(south==true)
              {
              west=true;
              north=false,south=false,east=false;
              continue;
              }
              if(east==true)
              {
              south=true;
              north=false,east=false,west=false;
              continue;
              }
            }

            if(commands[i]>=1 && commands[i]<=9)
            {
                if(north==true)
                {
                    for(int j=0;j<commands[i];j++)
                    {
                        y=y+1;
                        if(s.find({x,y})!=s.end())
                        {
                        y=y-1;
                        break;
                        }
                    }
                }
                if(south==true)
                {
                     for(int j=0;j<commands[i];j++)
                    {
                        y=y-1;
                        if(s.find({x,y})!=s.end())
                        {
                            y=y+1;
                            break;
                        }
                    }
                }
                if(east==true)
                {
                    for(int j=0;j<commands[i];j++)
                    {
                        x=x+1;
                        if(s.find({x,y})!=s.end())
                        {
                        x=x-1;    
                        break;
                        }
                    }
                }
                if(west==true)
                {
                    for(int j=0;j<commands[i];j++)
                    {
                        x=x-1;
                        if(s.find({x,y})!=s.end())
                        {
                        x=x+1;    
                        break;
                        }
                    }
                }
            }
            maxi = max(maxi, x * x + y * y);
        }
        return maxi;
    }
};