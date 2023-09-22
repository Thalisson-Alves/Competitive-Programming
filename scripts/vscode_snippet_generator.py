import json
import optparse
import os
import re
from pathlib import Path

if os.name == "nt":
    config_dir = os.getenv("APPDATA", '')
    assert config_dir, "APPDATA is not set"
else:
    config_dir = os.path.join(os.getenv("HOME", ''), ".config")
    assert config_dir, "HOME is not set"

snippets_path = Path(config_dir) / "Code" / "User" / "snippets" / "cpp.json"
code_path = Path(__file__).parent.parent / "code"

def gen_snippet():
    snippets = {}
    for file in code_path.glob("*.cpp"):
        with open(file, "r") as f:
            lines = f.read().splitlines()

        snippet = {
            "prefix": file.stem,
            "body": lines,
            "description": file.stem,
        }
        snippets[file.stem] = snippet

    return snippets

if __name__ == "__main__":
    optparser = optparse.OptionParser()
    optparser.add_option("-w", "--overwrite", action="store_true", dest="overwrite", default=False)

    (opts, _) = optparser.parse_args()

    if snippets_path.exists() and not opts.overwrite:
        with open(snippets_path, "r") as f:
            snippets = json.loads(re.sub(r"^\s*//.*", "", f.read(), flags=re.MULTILINE))
    else:
        snippets = {}

    failed = []
    for k, v in gen_snippet().items():
        if k not in snippets:
            snippets[k] = v
        else:
            failed.append(k)

    with open(snippets_path, "w") as f:
        json.dump(snippets, f, indent=4)

    if failed:
        print("Failed to add snippets: {}".format(", ".join(failed)))
    else:
        print("Successfully added snippets")
