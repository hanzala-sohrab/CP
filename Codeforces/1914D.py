from typing import List, Set
from enum import Enum


class Activity(Enum):
    NOTHING = 0
    SKIING = 1
    WATCH_MOVIE = 2
    PLAY_GAMES = 3


def solve(n: int, a: List[int], b: List[int], c: List[int]) -> int:
    dp = [
        [[[-1 for _ in range(2)] for _ in range(2)] for _ in range(2)] for _ in range(n)
    ]

    def f(
        day: int, can_go_skiing: int, can_watch_movie: int, can_play_games: int
    ) -> int:
        if day == n or (can_go_skiing + can_watch_movie + can_play_games == 0):
            return 0

        if dp[day][can_go_skiing][can_watch_movie][can_play_games] != -1:
            return dp[day][can_go_skiing][can_watch_movie][can_play_games]

        skiing = 0
        watch_movie = 0
        play_games = 0
        do_nothing = 0

        if can_go_skiing:
            skiing = a[day] + f(day + 1, 0, can_watch_movie, can_play_games)
        if can_watch_movie:
            watch_movie = b[day] + f(day + 1, can_go_skiing, 0, can_play_games)
        if can_play_games:
            play_games = c[day] + f(day + 1, can_go_skiing, can_watch_movie, 0)

        do_nothing = f(day + 1, can_go_skiing, can_watch_movie, can_play_games)
        dp[day][can_go_skiing][can_watch_movie][can_play_games] = max(
            skiing, watch_movie, play_games, do_nothing
        )
        return dp[day][can_go_skiing][can_watch_movie][can_play_games]

    return f(0, 1, 1, 1)


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        b = list(map(int, input().split()))
        c = list(map(int, input().split()))
        print(solve(n, a, b, c))
