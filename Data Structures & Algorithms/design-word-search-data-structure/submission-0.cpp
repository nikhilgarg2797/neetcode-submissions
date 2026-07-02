class TrieNode{
public:
    TrieNode* children[26];
    bool endOfWord;

    TrieNode()
    {
        for(int i=0; i<26; i++) children[i] = nullptr;
        endOfWord = false;
    }
};


class WordDictionary {
private:
    TrieNode* root;

    bool dfs(string& word, int index, TrieNode* node)
    {
        if(index == word.size())
            return node->endOfWord;

        char c = word[index];

        if(c == '.')
        {
            for(int i = 0; i < 26; i++)
            {
                if(node->children[i] &&
                   dfs(word, index + 1, node->children[i]))
                    return true;
            }

            return false;
        }

        int child = c - 'a';

        if(node->children[child] == nullptr)
            return false;

        return dfs(word, index + 1, node->children[child]);
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word)
    {
        TrieNode* cur = root;

        for(char c : word)
        {
            int idx = c - 'a';

            if(cur->children[idx] == nullptr)
                cur->children[idx] = new TrieNode();

            cur = cur->children[idx];
        }

        cur->endOfWord = true;
    }

    bool search(string word)
    {
        return dfs(word, 0, root);
    }
};
