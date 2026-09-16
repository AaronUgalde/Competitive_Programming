<!-- TODO before merging to the default branch:
     resolve every <<< FILL >>> marker below (screenshots, demo credentials,
     handles, and the metrics flagged inline). They are visible when rendered. -->

# Competitive Programming

> 600+ solved problems in C++ and Python across Codeforces, AtCoder and CSES — plus the contest
> template and stress-testing script I actually use.

<p>
  <img alt="C++" src="https://img.shields.io/badge/C%2B%2B-00599C?logo=cplusplus&logoColor=white">
  <img alt="Python" src="https://img.shields.io/badge/Python-3776AB?logo=python&logoColor=white">
  <img alt="Codeforces" src="https://img.shields.io/badge/Codeforces-1F8ACB?logo=codeforces&logoColor=white">
</p>

This is a working archive, not a curated showcase — it's where my contest practice lands.
I keep it public because how someone practices says more than a rating screenshot does.

---

## Contents

| Directory | Platform | Solutions |
|---|---|---|
| `codeforces/` | [Codeforces](https://codeforces.com/) | 547 |
| `Atcoder/` | [AtCoder](https://atcoder.jp/) | 50 |
| `cses/` | [CSES Problem Set](https://cses.fi/problemset/) | 12 |
| `tcmx2025/` | Training Camp MX 2025 | 6 |
| `pending/` | in progress / revisit | 1 |

*Counts as of 2026-09-15.*

**Profiles:** <!-- <<< FILL >>> add your handles — these are what a reviewer actually clicks -->
Codeforces `<<< handle >>>` · AtCoder `<<< handle >>>` · LeetCode `<<< handle >>>`

---

## Tooling

**`template.cpp`** — contest starter: `bits/stdc++.h`, fast I/O
(`sync_with_stdio(false)`, `cin.tie(nullptr)`), `ll`/`ull` aliases, `all()` / `sz()` macros, a
`dbg()` macro that writes to `stderr` so it never pollutes judged output, and a multi-test
`solve()` skeleton.

**`test.py`** — local stress tester. Runs a solution against brute force over generated inputs and
stops at the first mismatch, which is how you find the edge case before the judge does rather
than after.

```bash
g++ -std=c++17 -O2 -o sol solution.cpp
python test.py            # <<< FILL >>> document the actual flags/usage
```

---

## Why this is on my CV

Contest practice is the cheapest way I know to keep data structures and complexity analysis in
working memory rather than in a textbook. It's also directly load-bearing in my other work — the
graph clustering in my internship's deduplication pipeline and the spatial indexing in a geospatial
project were both easier because the underlying algorithms were already familiar.

I teach this material too, at **Club de Algoritmia (ESCOM)**, and compete in the **ICPC**.

---

## Notes

- Solutions are archived as submitted, so early ones are not necessarily how I'd write them now.
- Filenames follow each platform's problem IDs.
- Nothing here is a library — `template.cpp` is the only thing intended for reuse.
