from typing import List, Set
from enum import Enum


class Activity(Enum):
    NOTHING = 0
    SKIING = 1
    WATCH_MOVIE = 2
    PLAY_GAMES = 3


def solve(n: int, a: List[int], b: List[int], c: List[int]) -> int:
    def f(day: int, remaining_activities: Set[int]) -> int:
        if day == n or len(remaining_activities) == 1:
            return 0

        skiing = 0
        watch_movie = 0
        play_games = 0
        do_nothing = 0

        if Activity.SKIING in remaining_activities:
            remaining_activities.remove(Activity.SKIING)
            skiing = a[day] + f(day + 1, remaining_activities)
            remaining_activities.add(Activity.SKIING)

        if Activity.WATCH_MOVIE in remaining_activities:
            remaining_activities.remove(Activity.WATCH_MOVIE)
            watch_movie = b[day] + f(day + 1, remaining_activities)
            remaining_activities.add(Activity.WATCH_MOVIE)

        if Activity.PLAY_GAMES in remaining_activities:
            remaining_activities.remove(Activity.PLAY_GAMES)
            play_games = c[day] + f(day + 1, remaining_activities)
            remaining_activities.add(Activity.PLAY_GAMES)

        do_nothing = f(day + 1, remaining_activities)

        return max(skiing, watch_movie, play_games, do_nothing)

    return f(
        0,
        set(
            [
                Activity.NOTHING,
                Activity.SKIING,
                Activity.WATCH_MOVIE,
                Activity.PLAY_GAMES,
            ]
        ),
    )


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        b = list(map(int, input().split()))
        c = list(map(int, input().split()))
        print(solve(n, a, b, c))
