
import os
import subprocess

def process_file(file_path):
    current_path = os.getcwd()
    path_stack = [current_path]

    with open(file_path, 'r') as f:
        for line in f:
            line = line.strip()

            if not line:
                continue

            if line.startswith("/.."):
                if len(path_stack) > 1:
                    path_stack.pop()
                    os.chdir(path_stack[-1])
                    print(f"🔙 Back to {os.getcwd()}")
                else:
                    print("⚠️ Already at root directory")
            elif line.startswith("/"):
                folder_name = line[1:]
                os.makedirs(folder_name, exist_ok=True)
                os.chdir(folder_name)
                path_stack.append(os.getcwd())
                print(f"📁 Entered directory: {os.getcwd()}")
            else:
                repo_url = "https://github.com/EpitechPromo2026/" + line + ".git"
                repo_name = repo_url.rstrip('/').split('/')[-1].replace('.git', '')
                try:
                    subprocess.run(["git", "clone", repo_url], check=True)
                    repo_path = os.path.join(os.getcwd(), repo_name)
                    git_dir = os.path.join(repo_path, ".git")
                    if os.path.isdir(git_dir):
                        subprocess.run(["rm", "-rf", git_dir], check=True)
                        print(f"✅ Cloned and cleaned: {repo_name}")
                    else:
                        print(f"⚠️ .git directory not found in {repo_name}")
                except subprocess.CalledProcessError as e:
                    print(f"❌ Failed to clone {repo_url}: {e}")

process_file("repos.txt") # Remplace par ton fichier d'entrée