let
unstable = import (fetchTarball https://nixos.org/channels/nixos-unstable/nixexprs.tar.xz) { };
in
with import <nixpkgs> {};
let
	opencvGtk = opencv.override
	(old : { enableGtk2 = true; });
	opencv4-override = unstable.opencv4.override
	(old : { enableGtk3 = true; enableDocs = true; enableCuda = true; enableFfmpeg = true; });
in {
  surfaces = stdenv.mkDerivation rec {
    name = "sepplesar";
    buildInputs = [
      clang_6

			opencvGtk
			opencv4-override

      pkgconfig
    ];
  };
}

