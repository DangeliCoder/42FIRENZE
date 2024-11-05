
For adding the management of command "exit" in file "utils1.c" you must change the line :

		status = prepare_command(&argv_c2[i][0], &argv_c2[i][1],
				argv[i + 1], env);

with line :

		status = prepare_command2(&argv_c2[i][0], &argv_c2[i][1],
				argv[i + 1], env);

and the line :

		status = prepare_command(&argv_c2[i][0], &argv_c2[i][1],
				argv[i + 2], env);

with line :

		status = prepare_command2(&argv_c2[i][0], &argv_c2[i][1],
				argv[i + 2], env);

Bye.
