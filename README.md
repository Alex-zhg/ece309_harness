# ece309_harness

A minimal LLM agent harness in C, built using Specification Driven Development (SDD) to "vibe-code" using Google Gemini.

A terminal-based loop using user input and providing a response dictated by a mock model function, mimicking an LLM without calling an LLM API.
The core loop features a minimal context management system allowing the storage of up to 255 user typed characters, safely allocating and managing memory.
