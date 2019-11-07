#!/usr/bin/ruby

load "rumy-env.rb"

# Clear Environment
clear_env

# ENV["PATH"] = "/usr/bin/:/bin/:/usr/local/bin/"
add_env_path "/usr/bin/"
add_env_path "/bin/"
add_env_path "/usr/local/bin/"

add_env "RUBYLIB", "/home/masayuki/work/rumy-make/src"

show_env
