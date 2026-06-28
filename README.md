# Hangman

A terminal Hangman game written in C++. Guess the secret word one letter at a time — or watch a stick figure slowly lose the will to live.

Zero dependencies. Just `g++`, a header full of adjectives, and the quiet dignity of a man dangling from a gallows drawn with raw string literals.

```
___________
| / |
|/ ( )
|   |
|  / \
|
```

---

## Gameplay

A word is picked at random from a list of ~2200 adjectives. Then — generously — some letters are pre-revealed before you even start: each position has a randomized chance of being shown (roughly 33–66% depending on a layered coin-flip system).

You then guess the remaining letters one at a time. You get **6 lives**. Every wrong guess costs one and advances the gallows one grim stage. Run out of guesses and the man drops. Guess the full word and you win.

Words containing spaces or hyphens are filtered out at startup — `isValid()` rejects them, so you'll never be asked to guess `"ad hoc"` or `"black-and-white"`. You're welcome.

---

## The Word List

`definitions.hpp` contains a single `inline std::vector<std::string>` called `wordlist` — **2220 lines** of English words, from `"aback"` to `"zany"`. At 115 KB it is, by a wide margin, the largest file in the project.

Some highlights lurking in there: `"axiomatic"`, `"quixotic"`, `"ossified"`, `"evanescent"`, `"dysfunctional"`. The word list does not pull punches.

---

## The Gallows (ASCII art)

`print_state(int lives)` renders 7 stages via raw string literals:

| Lives | State |
|---|---|
| 6 | Empty gallows pole |
| 5 | Crossbeam added |
| 4 | Rope added |
| 3 | Head appears |
| 2 | Body added |
| 1 | One leg |
| 0 | Two legs. Game over. |

---

## Building

No dependencies beyond a C++20-capable `g++`.

```bash
git clone https://github.com/HassanIQ777/Hangman
cd Hangman
make
```

```bash
# Release build (default, -O2 -march=native -flto)
make

# Debug build (ASan + UBSan, -Og)
make debug

# Build and run immediately
make run

# Clean
make clean
```

The binary lands at `./hangman`.

---

## Running

```bash
./hangman
```

Works on Linux, and anywhere else `g++` and a terminal exist. Termux included — it's literally just stdin/stdout.

---

## Project Structure

```
Hangman/
├── main.cpp          # the entire game loop
├── definitions.hpp   # wordlist, print_state(), isValid(), lives
├── Makefile
└── LICENSE           # MIT
```

The split is: game logic in `main.cpp`, everything else shoved into `definitions.hpp`. Unconventional. Functional. Committed.

---

## License

MIT — guess freely.

---