with import <nixpkgs> {};
{
  surfaces = stdenv.mkDerivation rec {
    name = "surfaces";
    buildInputs = [
      clang
      opencv
    ];
  };
}

