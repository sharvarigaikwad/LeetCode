class Solution {
public:
    struct vertex{
        int group = -1;
        vector<string> edges;
    };
    void mark_adj(map<string, vertex> &sim_graph, string w, int key)
    {
        vector<string> edge_list = sim_graph[w].edges;
        for(string edge: edge_list)
        {
            if(sim_graph[edge].group == -1)
            {
                sim_graph[edge].group = key;
                mark_adj(sim_graph, edge, key);
            }
        }
    }
    void mark_all_connected(map<string, vertex> &sim_graph)
    {
        map<string, vertex>::iterator itr;
        int group_key = 1;
        for(itr = sim_graph.begin(); itr != sim_graph.end(); itr++)
        {
            if(itr->second.group == -1)
            {
                sim_graph[itr->first].group = group_key;
                mark_adj(sim_graph, itr->first, group_key);
                group_key++;
            }
        }
    }
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        string w1, w2;
        map<string, vertex> similarity_graph;
        for(vector<string> sim: pairs)
        {
            w1 = sim[0], w2 = sim[1];
            if(similarity_graph.count(w1))
            {
                similarity_graph[w1].edges.push_back(w2);
            }
            else
            {
                vertex v;
                v.edges = {w2};
                similarity_graph[w1] = v;
            }
            if(similarity_graph.count(w2))
            {
                similarity_graph[w2].edges.push_back(w1);
            }
            else
            {
                vertex v;
                v.edges = {w1};
                similarity_graph[w2] = v;
            }
        }
        mark_all_connected(similarity_graph);
        int i, len = words1.size();
        if(words2.size() != len)
        {
            return false;
        }
        for(i = 0; i < len ; i++)
        {
            if(similarity_graph[words1[i]].group != similarity_graph[words2[i]].group)
                return false;
        }
        return true;
    }
};