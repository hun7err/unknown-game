io.write("Initial val: ", foo:get_bar(), "\n")
foo:set_bar(42)
value = foo:get_bar()

io.write("From LUA: ", value, "\n")