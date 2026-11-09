# cf-autopush

Polls the Codeforces API and commits + pushes accepted solutions.

- `cf-autopush` – the script (symlinked from `~/.local/bin/cf-autopush`)
- `cf-autopush.service` / `.timer` – systemd user units (copy to `~/.config/systemd/user/`)

Install:

    ln -sf "$PWD/cf-autopush" ~/.local/bin/cf-autopush
    cp cf-autopush.{service,timer} ~/.config/systemd/user/
    systemctl --user daemon-reload && systemctl --user enable --now cf-autopush.timer

Java: if `CONTESTINDEX.java` is missing, `Solution.java` is copied to it.
