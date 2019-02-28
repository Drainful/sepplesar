with import <nixpkgs> {};
{
  surfaces = stdenv.mkDerivation rec {
    name = "surfaces";
    buildInputs = [
      clang_6
      opencv
    ];
  };
}

