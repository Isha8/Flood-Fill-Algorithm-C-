#include <iostream>
#include <vector>
#include <utility>
#include <bits/stdc++.h>

bool if_in_list(std::vector <std::pair<int,int>> list,std::pair<int,int> x ){
    if (std::find(list.begin(),list.end(),x) != list.end()){
        return true;
        }
    else{return false;}
    }

int flood_fill(std::vector<std::vector <int>> world, int x, int y, auto color){
        int r,c;
        std::vector<std:: pair<int,int>> list_of_all;
        std::vector<std::pair<int,int>> current;
        current.push_back(std::make_pair(x,y));
        std::vector<std::pair<int,int>> done;
        int a = world[x][y];
        //std::cout<< list_of_all.size();
        
        while(!current.empty()){
            std::pair <int,int> curr;
            curr = current.back();
            current.pop_back();
            r = curr.first;
            c = curr.second;
            list_of_all.push_back(curr);
            done.push_back(curr);
            
            //std::cout << list_of_all.size();
            
            if (r<world.size()-1){
                if (world[r+1][c] == a){
                    std::pair<int,int> pt = std::make_pair(r+1,c);
                    if (!if_in_list(current,pt) && !if_in_list(done,pt)){
                        current.push_back(pt);                    
                    }
                    list_of_all.push_back(pt);                    
                }
                if (r >= 1){
                    if (world[r-1][c] == a){
                        std::pair<int,int> pt = std::make_pair(r-1,c);
                        if(!if_in_list(current,pt) && !if_in_list(done,pt)){
                            current.push_back(pt);                            
                        }
                        list_of_all.push_back(pt);
                    }
                }       
            }
            else if(r>=1){
                if (world[r-1][c] == a){
                    std::pair<int,int> pt = std::make_pair(r-1,c);
                    if (!if_in_list(current,pt) && !if_in_list(done,pt)){
                        current.push_back(pt);                    
                    }
                    list_of_all.push_back(pt);                    
                }
                if (r < world.size() - 1){
                    if (world[r+1][c] == a){
                        std::pair<int,int> pt = std::make_pair(r+1,c);
                        if(!if_in_list(current,pt) && !if_in_list(done,pt)){
                            current.push_back(pt);                            
                        }
                        list_of_all.push_back(pt);
                    }
                }       
            }
                  
            if (c < world[0].size()-1){
                if (world[r][c+1] == a){
                    std::pair<int,int> pt = std::make_pair(r,c+1);
                    if (!if_in_list(current,pt) && !if_in_list(done,pt)){
                        current.push_back(pt);                    
                    }
                    list_of_all.push_back(pt);
                }
            
                if (c >= 1){
                    if (world[r][c-1] == a){
                        std::pair<int,int> pt = std::make_pair(r,c-1);
                        if(!if_in_list(current,pt) && !if_in_list(done,pt)){
                            current.push_back(pt);                            
                        }
                        list_of_all.push_back(pt);
                    }
                }          
            }
            
            else if(c>=1){
                if (world[r][c-1] == a){
                    std::pair<int,int> pt = std::make_pair(r,c-1);
                    if (!if_in_list(current,pt) && !if_in_list(done,pt)){
                        current.push_back(pt);                    
                    }
                    list_of_all.push_back(pt);                    
                }
                if (c < world.size() - 1){
                    if (world[r][c+1] == a){
                        std::pair<int,int> pt = std::make_pair(r,c+1);
                        if(!if_in_list(current,pt) && !if_in_list(done,pt)){
                            current.push_back(pt);                            
                        }
                        list_of_all.push_back(pt);
                    }
                }       
            }
                
        }   
                 
        std::vector<std::vector<int>> new_world = world;
        for (auto k : list_of_all){
            new_world[k.first][k.second] = color;
            } 
        for (int i = 0; i<new_world.size();i++){
            for (auto k: new_world[i]){
                std::cout<< k << " ";
                }
            std::cout << "\n";
            }
        return 0;
    }


int main() { 
        
    std::vector <std::vector <int> > world{{0,1,1,2,0,0},
                                           {1,1,2,2,1,1},
                                           {0,0,0,1,1,2},
                                           {1,0,1,2,1,2},
                                           {2,2,2,1,1,1},
                                           {1,1,1,1,0,0}
                                           };
    auto color = 8;
    int x=4, y= 4;
    flood_fill(world,x,y,color);
    return 0;
    }