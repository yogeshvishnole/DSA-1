#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <unordered_set>
#include <climits>
using namespace std;

class TreeNode
{
public:
    string data;
    vector<TreeNode *> childrens;

    TreeNode(string data)
    {
        this->data = data;
        this->childrens = {};
    }
};

TreeNode *searchNodeInTree(TreeNode *root, string searchKey)
{
    if (!root)
        return nullptr;

    if (root->data == searchKey)
    {
        return root;
    }

    for (int i = 0; i < root->childrens.size(); i++)
    {
        TreeNode *el = searchNodeInTree(root->childrens[i], searchKey);
        if (el)
            return el;
    }
    return nullptr;
}

void findSequencesHelper(TreeNode *root, vector<vector<string>> &sequences, string targetWord, vector<string> &curSequence, int minLength)
{
    if (!root)
        return;
    curSequence.push_back(root->data);
    if (root->data == targetWord)
    {
        if (curSequence.size() == minLength)
        {
            sequences.push_back(curSequence);
        }
        curSequence.pop_back();
        return;
    }
    for (int i = 0; i < root->childrens.size(); i++)
    {
        findSequencesHelper(root->childrens[i], sequences, targetWord, curSequence, minLength);
    }

    curSequence.pop_back();
}

vector<vector<string>>
findSequences(string beginWord, string endWord,
              vector<string> &wordList)
{
    int minLength = INT_MAX;
    vector<vector<string>> sequences;
    unordered_set<string> set;

    for (int i = 0; i < wordList.size(); i++)
    {
        set.insert(wordList[i]);
    }

    TreeNode *root = new TreeNode(beginWord);

    queue<pair<string, int>> wordQueue;
    wordQueue.push({beginWord, 1});
    set.erase(beginWord);

    while (!wordQueue.empty())
    {
        string curWord = wordQueue.front().first;
        int curLevel = wordQueue.front().second;

        TreeNode *curParent = searchNodeInTree(root, curWord);

        wordQueue.pop();

        for (int i = 0; i < curWord.size(); i++)
        {
            char curLetter = curWord[i];

            for (char charIter = 'a'; charIter <= 'z'; charIter++)
            {
                if (charIter == curLetter)
                    continue;
                curWord[i] = charIter;

                if (set.find(curWord) != set.end())
                {
                    curParent->childrens.push_back(new TreeNode(curWord));
                    if (curWord == endWord)
                    {
                        minLength = min(minLength, curLevel + 1);
                        continue;
                    }
                    wordQueue.push({curWord, curLevel + 1});
                    set.erase(curWord);
                }
            }
            curWord[i] = curLetter;
        }
    }

    vector<string> curSeq;
    findSequencesHelper(root, sequences, endWord, curSeq, minLength);

    return sequences;
}

int main()
{

    string startWord = "der";
    string targetWord = "dfs";
    vector<string> wordList =
        {
            "des",
            "der",
            "dfr",
            "dgt",
            "dfs",
        };

    vector<vector<string>> ans = findSequences(startWord, targetWord, wordList);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}