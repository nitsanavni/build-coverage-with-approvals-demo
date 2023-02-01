```
sudo apt install clang-12 --install-suggests -y
curl -1sLf 'https://dl.cloudsmith.io/public/mull-project/mull-stable/setup.deb.sh' | sudo -E bash
sudo apt-get update
sudo apt-get install mull-12
mull-runner-12 --version
```
