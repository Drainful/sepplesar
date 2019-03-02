with import <nixpkgs> {};
let
	opencvGtk = opencv.override (old : { enableGtk2 = true; });
in {
  surfaces = stdenv.mkDerivation rec {
    name = "sepplesar";
    buildInputs = [
      clang_6
      opencvGtk
      pkgconfig
    ];
  };
}

