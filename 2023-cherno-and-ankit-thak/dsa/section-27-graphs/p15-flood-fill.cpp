#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int origColor = image[sr][sc];
    vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    queue<pair<int, int>> q;
    q.push({sr, sc});
    // I mutated the same input variable but dont do it, always copy the input variable and make the
    // changes in copy it is a software engineering principle, never change the original copy of data
    // otherwise you will corrupt the data, then you will have nothing to work with.
    image[sr][sc] = color;

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i = 0; i < directions.size(); i++)
        {
            int x = r + directions[i].first;
            int y = c + directions[i].second;
            if (x >= 0 && y >= 0 && x < image.size() && y < image[0].size() && image[x][y] != color && image[x][y] == origColor)
            {
                q.push({x, y});
                image[x][y] = color;
            }
        }
    }
    return image;
}

int main()
{
    vector<vector<int>> image = {{1, 1, 1},
                                 {1, 1, 0},
                                 {1, 0, 1}};
    int sr = 1;
    int sc = 1;
    int color = 2;

    floodFill(image, sr, sc, color);

    for (auto vec : image)
    {
        for (auto el : vec)
        {
            cout
                << el << " ";
        }
        cout << endl;
    }
}
