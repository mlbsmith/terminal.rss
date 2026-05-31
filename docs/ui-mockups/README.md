# Terminal RSS Reader UI Mockups

These are ASCII-only terminal UI mockups for three different RSS reader directions. They are design artifacts only; no C source, headers, build files, tests, image assets, binary files, or application implementation were changed.

The mockups intentionally avoid PNG, SVG, Unicode box drawing, and other non-ASCII characters so review tools should treat this as a plain Markdown text change.

## Version 1 - Pane Classic

A familiar three-pane reader with feeds, article list, and preview/reader content visible at once.

### Main page

```text
terminal.rss  v0.1                         23 unread        [?] help  [q] quit
--------------------------------------------------------------------------------------
 FEEDS                         ARTICLES                         PREVIEW
 -----                         --------                         -------
 > All feeds             23    * SQLite 3.51 adds ...           SQLite 3.51 release notes
   Beej's C Notes         4    * Why terminal apps still...     Published: Today 09:12
   Systems Weekly        11    o Undefined behavior case...     Source: Systems Weekly
   RSS Spec Watch         2    o Tiny XML parser tradeoffs
   Personal blogs         6    o Curl vs sockets for RSS       The interesting part for our

 TAGS                          FILTER: unread                   first milestone is not networking.
 #c             9              -------------------------        It is keeping ownership rules
 #terminal      7              Use up/down, Enter to open,      obvious: which string owns title,
 #parsing       3              e to edit feeds, / to search.    link, and description?

--------------------------------------------------------------------------------------
Status: local cache loaded from ./feeds.cache        Next refresh disabled for milestone 1
```

### Feed editor menu

```text
terminal.rss  feed editor                                      [Esc] back  [q] quit
--------------------------------------------------------------------------------------
 FEED SOURCES                                      DETAILS
 ------------                                      -------
 > [x] Systems Weekly                             Name: Systems Weekly
   URL: file://samples/systems-weekly.xml         URL:  file://samples/systems-weekly.xml
                                                   Tags: c, systems, parsing
   [x] Beej's C Notes                             Last read: 2026-05-30 19:44 UTC
   URL: file://samples/beej-c.xml                 Unread: 11

   [ ] Example Tech RSS                           ACTIONS
   URL: https://example.com/rss.xml               -------
                                                  [a] add feed   [r] rename
                                                  [t] edit tags  [d] disable
                                                  [x] delete     [v] validate local XML

--------------------------------------------------------------------------------------
Prompt: What owns this URL string after editing: stack buffer, heap allocation, or static text?
```

### Reader view

```text
terminal.rss  article reader                       [b] back  [o] open link  [q] quit
--------------------------------------------------------------------------------------
SQLite 3.51 adds a quieter release cycle
Systems Weekly - Today 09:12 - https://example.test/sqlite-351

The release notes are less exciting than the engineering habit they reveal:
small changes, clear compatibility promises, and boringly repeatable builds.

For our terminal RSS reader, that suggests a useful first question:

  If a parser returns an item title, who is responsible for freeing it?

A pleasant reader view can hide complexity from the user, but the program
still needs explicit ownership rules behind every field in every struct.

--------------------------------------------------------------------------------------
1/18 lines  up/down scroll  m mark unread  s save  Source cached from local XML fixture
```

## Version 2 - Command Deck

A keyboard-first, command/search driven design with dense lists and Vim-like navigation hints.

### Main page

```text
+-- terminal.rss ------------------------------------------------------------------+
| / unread from:systems tag:c                                      23 hits  F1 help |
+----------------------------------------------------------------------------------+

  TIME     FEED             TITLE                                      TAGS
  -----    -------------    ---------------------------------------    -----------
> 09:12    Systems Weekly   SQLite 3.51 adds a quieter release cycle    c,builds
  08:40    Beej C Notes     Reading files one line at a time            c,io
  Yesterday RSS Spec Watch  What guid means when links change           rss
  Friday   Personal blogs   Why I still like terminal dashboards        terminal
  Friday   Systems Weekly   A tiny parser, a large responsibility       parsing

+-- commands ----------------------------------------------------------------------+
| enter open | e feeds | r refresh | m mark read | : command | q quit              |
+----------------------------------------------------------------------------------+
```

### Feed editor menu

```text
+-- feed commands -----------------------------------------------------------------+
| :feed add <path-or-url>   :feed disable 2   :feed tag 1 c,systems   Esc back     |
+----------------------------------------------------------------------------------+

  #  ON  NAME              LOCATION                                  STATUS
  -  --  --------------    ---------------------------------------   -------------
> 1  yes Systems Weekly    file://samples/systems-weekly.xml         ok - 11 unread
  2  yes Beej C Notes      file://samples/beej-c.xml                 ok - 4 unread
  3  no  Example Tech RSS  https://example.com/rss.xml               disabled

+-- validation --------------------------------------------------------------------+
| Selected feed has title, link, and 18 items. Missing descriptions are tolerated. |
+----------------------------------------------------------------------------------+

Question before implementing: should validation mutate feed state, or just report?
```

### Reader view

```text
+-- article 1 of 23 ---------------------------------------------------------------+
| SQLite 3.51 adds a quieter release cycle                         Systems Weekly |
+----------------------------------------------------------------------------------+
  Published Today 09:12 UTC     Link https://example.test/sqlite-351

  The release notes are less exciting than the engineering habit they reveal:
  small changes, clear compatibility promises, and boringly repeatable builds.

  In C, the quiet part of a design is often the ownership model. A reader can
  look minimal while its structs make every allocation and free visible.

  Trace it:
    parse_item() -> title pointer -> item.title -> free_item()

+-- keys --------------------------------------------------------------------------+
| j/k scroll | n/p article | b list | y copy link | o browser | q quit             |
+----------------------------------------------------------------------------------+
```

## Version 3 - Card Console

A dashboard-like terminal design that uses bordered cards to make feeds, queues, and reader progress feel softer and more approachable.

### Main page

```text
 terminal.rss                                              Sunday, 31 May 2026
+----------------------+ +----------------------------+ +--------------------------+
| Inbox                | | Today                      | | Reading Queue            |
| 23 unread            | | * SQLite 3.51 release      | | 1. Tiny XML parser notes |
| 5 feeds              | | * Files, fgets, and EOF    | | 2. RSS guid semantics    |
| Last refresh: local  | | o Terminal dashboards      | | 3. Curl later, files now |
+----------------------+ +----------------------------+ +--------------------------+

+----------------------------------------------------------------------------------+
| Focus feed: Systems Weekly                                                       |
| [############....] 11 unread   Tags: c systems parsing   Source: local fixture   |
| Next useful action: open a saved XML file and print titles before adding network. |
+----------------------------------------------------------------------------------+

Keys: Tab switch cards | Enter open | e edit feeds | ? explain this screen | q quit
```

### Feed editor menu

```text
 terminal.rss / feeds                                      changes not saved yet
+------------------------------------+ +-------------------------------------------+
| Feed cards                         | | Edit selected feed                       |
| > Systems Weekly        11 unread  | | Name       Systems Weekly                |
|   Beej C Notes           4 unread  | | Location   file://samples/systems.xml    |
|   RSS Spec Watch         2 unread  | | Tags       c, systems, parsing           |
|   Personal blogs         6 unread  | | Enabled    yes                           |
|   Example Tech RSS       disabled  | |                                           |
+------------------------------------+ | Preview validates 18 items; 0 fatal errs. |
                                      +-------------------------------------------+

+----------------------------------------------------------------------------------+
| [a] add  [space] toggle  [Enter] edit field  [s] save  [u] undo  [Esc] cancel    |
+----------------------------------------------------------------------------------+
```

### Reader view

```text
 terminal.rss / Systems Weekly / article 1 of 23
+----------------------------------------------------------------------------------+
| SQLite 3.51 adds a quieter release cycle                                         |
| Today 09:12 UTC - https://example.test/sqlite-351                                |
+----------------------------------------------------------------------------------+

  The release notes are less exciting than the engineering habit they reveal:
  small changes, clear compatibility promises, and boringly repeatable builds.

  A card-style reader is friendly, but ask the unfriendly C question underneath:
  when this screen closes, which allocations must disappear with it?

+----------------------------------------------------------------------------------+
| Progress [#######.............] 36%     b back | n next | m unread | q quit      |
+----------------------------------------------------------------------------------+
```

Before choosing one direction, compare what each design teaches you to model in C: pane state, command parsing, navigation focus, string ownership, and how much redraw logic you want to write by hand.
