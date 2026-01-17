from typing import List, Set
from enum import Enum


class Activity(Enum):
    NOTHING = 0
    SKIING = 1
    WATCH_MOVIE = 2
    PLAY_GAMES = 3


def solve(n: int, a: List[int], b: List[int], c: List[int]) -> int:
    dp = [[-1] * 7 for _ in range(n + 1)]

    def f(day: int, remaining_activities: int) -> int:
        if day == n or remaining_activities == 0:
            return 0

        if dp[day][remaining_activities] != -1:
            return dp[day][remaining_activities]

        skiing = 0
        watch_movie = 0
        play_games = 0
        do_nothing = 0

        if (
            remaining_activities == 1
            or remaining_activities == 4
            or remaining_activities == 6
        ):
            remaining_activities -= Activity.SKIING.value
            skiing = a[day] + f(day + 1, remaining_activities)
            remaining_activities += Activity.SKIING.value

        if remaining_activities > 4 or remaining_activities == 2:
            remaining_activities -= Activity.WATCH_MOVIE.value
            watch_movie = b[day] + f(day + 1, remaining_activities)
            remaining_activities += Activity.WATCH_MOVIE.value

        if remaining_activities > 2:
            remaining_activities -= Activity.PLAY_GAMES.value
            play_games = c[day] + f(day + 1, remaining_activities)
            remaining_activities += Activity.PLAY_GAMES.value

        do_nothing = f(day + 1, remaining_activities)
        dp[day][remaining_activities] = max(skiing, watch_movie, play_games, do_nothing)
        return dp[day][remaining_activities]

    return f(0, 6)


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        b = list(map(int, input().split()))
        c = list(map(int, input().split()))
        print(solve(n, a, b, c))
