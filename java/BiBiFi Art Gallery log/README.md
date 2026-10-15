# BiBiFi "Art Gallery" access log (Secure Software Engineering, University of Bonn)

Team project from the Build-It-Break-It-Fix-It (BiBiFi) contest, build phase (Java 11). An art gallery wants to log which persons (employees and guests) enter and leave the gallery and its rooms. Two command-line programs had to be written: `logappend` adds events to a log file and `logread` queries it. Reading or changing the log must be possible only with a secret token, and implausible events (e.g. entering a room without being in the gallery) must be rejected.

- `l_append/LogAppend.java` - argument parsing and validation (`picocli`), batch mode (`-B`), the plausibility check of each event against the person's previous state, and writing the log as encrypted JSON.
- `l_read/LogRead.java` - decrypts the log and prints the state of the gallery (`-S`), the rooms visited by a person (`-R`) or the time a person spent in the gallery (`-T`).
- `makefile`, `stub.sh`, `MANIFEST_*.MF` - build the self-executable `logappend` / `logread` jars; `examples/` - sample batch files.

Concepts used: strict input validation with `invalid` + exit code 255 on any error, a key derived from the token (PBKDF2-HMAC-SHA256 with a random salt), AES-CBC encryption with a random IV (both kept in a separate `<log>_config` file), Gson for the JSON structure, and a state machine for the gallery / room events.

Team code: it was written by the group together (name / room validation, the first encrypted JSON write path, decryption in `logread`, the event plausibility checks and test batch files). 
