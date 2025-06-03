import os
import re
from pathlib import Path
from collections import defaultdict

# Dossier du projet Rust
SRC_DIR = Path("src")
HEADER_IN = Path("temp.h")
HEADER_OUT = Path("libft.h")

# Étape 1 : récupérer les signatures de fonctions depuis my_header.h
with open(HEADER_IN) as f:
    lines = f.readlines()

# Ne garder que les lignes de fonctions externes
fn_lines = [line.strip() for line in lines if re.match(r'^(uint\d+_t|uintptr_t).*\);$', line.strip())]

# Étape 2 : créer un mapping nom -> signature
signatures = {}
for line in fn_lines:
    match = re.match(r'.+\s+(ft_[a-z0-9_]+)\(.*', line)
    if match:
        fname = match.group(1)
        signatures[fname] = line

# Étape 3 : retrouver les fonctions par dossier
grouped = defaultdict(list)

for root, _, files in os.walk(SRC_DIR):
    for file in files:
        if file.startswith("ft_") and file.endswith(".rs"):
            module = Path(root).name
            fname = file.removesuffix(".rs")
            if fname in signatures:
                grouped[module].append(signatures[fname])

# Étape 4 : générer le header final
with open(HEADER_OUT, "w") as out:
    out.write("#ifndef FT_H\n")
    out.write("#define FT_H\n\n")
    out.write("#include <stdarg.h>\n")
    out.write("#include <stdbool.h>\n")
    out.write("#include <stdint.h>\n")
    out.write("#include <stdlib.h>\n\n")

    for module in sorted(grouped):
        out.write(f"// {module.capitalize()}\n")
        for sig in sorted(grouped[module]):
            out.write(sig + "\n")
        out.write("\n")

    out.write("#endif /* FT_H */\n")
