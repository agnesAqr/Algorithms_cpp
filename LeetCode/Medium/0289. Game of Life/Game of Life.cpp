                        changes.emplace(r, c);
                if (board[r][c] == 1)
                {
                    if (live < 2)
                    }
                }
                    {
                        changes.emplace(r, c);
                        break;
                    if (board[r][c] == 1 && live > 3)
                }
                else
                {
                    if (live == 3)
                        changes.emplace(r, c);
                }
            }
        }

        while (!changes.empty())
        {
            auto [r, c] = changes.front();
            changes.pop();
            int newVal = board[r][c] == 0 ? 1 : 0;
            board[r][c] = newVal;
        }
    }
};
