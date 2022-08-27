class Solution
{
public:
    int depth(string seq)
    {
        int c_depth = 0;
        int max_depth = 0;
        for (size_t i = 0; i < seq.size(); ++i)
        {
            if (seq[i] == '(')
                c_depth++;
            else
                --c_depth;
            
            if (max_depth < c_depth) max_depth = c_depth;
        }
        return max_depth;
    }
    
    vector<int> maxDepthAfterSplit(string seq) {
        std::vector<int> data(seq.size());
        
        // compute depth for each bracket
        int c_depth = 0;
        int max_depth = 0;
        for (size_t i = 0; i < seq.size(); ++i)
        {            
            if (seq[i] == '(')
            {
                if (max_depth < c_depth) max_depth = c_depth;
                data[i] = c_depth++;
            }
            else
            {
                data[i] = --c_depth;
                if (max_depth < c_depth) max_depth = c_depth;
            }
        }
                
        for (size_t i = 0; i < data.size(); ++i)
        {
            if (data[i] / static_cast<float>(max_depth) > .5f)
                data[i] = 1;
            else 
                data[i] = 0;
        }
        
        return data;
    }
};