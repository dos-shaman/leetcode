class Solution {
public:
    int lengthLongestPath(string const& input) const noexcept
    {
        bool is_file        = false;
        auto curr_depth     = 0ul;
        auto curr_word_len  = 0ul;
        auto curr_max_path  = 0ul;
        std::stack<std::size_t> path;
        auto process_node = [&]()
        {
            while(path.size() > curr_depth)
            {
                path.pop();
            }
            path.push(path.empty() ? curr_word_len : path.top() + 1 + curr_word_len);
            if(is_file)
            {
                curr_max_path = std::max(path.top(), curr_max_path);
            }
            is_file = false;
            curr_depth = 0ul;
            curr_word_len = 0ul;
        };

        for(auto ch : input)
        {
            if(ch == '\n')
            {
                process_node();
            }
            else if(ch == '\t')
            {
                ++curr_depth;
            }
            else
            {
                ++curr_word_len;
                if(ch == '.')
                {
                    is_file = true;
                }
            }
        }
        process_node();
        return curr_max_path;
    }
};