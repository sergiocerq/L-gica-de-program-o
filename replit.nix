{ pkgs }: {
	deps = [
		pkgs.ls
  pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}