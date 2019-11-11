#!/usr/bin/ruby

load "rumy-env.rb"

# Clear Environment
clear_env

# ENV["PATH"] = "/usr/bin/:/bin/:/usr/local/bin/"
add_env_path "/usr/bin/"
add_env_path "/bin/"
add_env_path "/usr/local/bin/"

add_env "RUBYLIB", "/home/msyksphinz/work/rumy-make/src"
add_env "RISCV", "/home/msyksphinz/riscv64"

show_env
