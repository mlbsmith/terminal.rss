# Terminal RSS Reader UI Mockups

These are static SVG screenshot mockups for three different terminal UI directions. They are design artifacts only; no C source, headers, build files, tests, or application implementation were changed.

## Version 1 — Pane Classic

A familiar three-pane reader with feeds, article list, and preview/reader content visible at once.

- Main page: [`v1-pane-classic-main.svg`](v1-pane-classic-main.svg)
- Feed editor menu: [`v1-pane-classic-editor.svg`](v1-pane-classic-editor.svg)
- Reader view: [`v1-pane-classic-reader.svg`](v1-pane-classic-reader.svg)

## Version 2 — Command Deck

A keyboard-first, command/search driven design with dense lists and Vim-like navigation hints.

- Main page: [`v2-command-deck-main.svg`](v2-command-deck-main.svg)
- Feed editor menu: [`v2-command-deck-editor.svg`](v2-command-deck-editor.svg)
- Reader view: [`v2-command-deck-reader.svg`](v2-command-deck-reader.svg)

## Version 3 — Card Console

A dashboard-like terminal design that uses bordered cards to make feeds, queues, and reader progress feel softer and more approachable.

- Main page: [`v3-card-console-main.svg`](v3-card-console-main.svg)
- Feed editor menu: [`v3-card-console-editor.svg`](v3-card-console-editor.svg)
- Reader view: [`v3-card-console-reader.svg`](v3-card-console-reader.svg)

Before choosing one direction, compare what each design teaches you to model in C: pane state, command parsing, navigation focus, string ownership, and how much redraw logic you want to write by hand.
