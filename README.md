UniPhier BL
===========

First stage boot loader for UniPhier 64bit SoCs.  This is supposed to be loaded
by the Boot ROM and runs in the on-chip SRAM.  After basic initialization of SoC
and DRAM, this loader expands the next image into the DRAM, then hands the
control over to it.  Typically, the next image is [Trusted Firmware-A] (TF-A)
BL2 (at EL3) [1].

[Trusted Firmware-A]: https://www.trustedfirmware.org
[1]: Trusted Firmware-A was originally called ARM Trusted Firmware.  It was
     renamed for consistency and disambiguation when Arm Ltd. introduced
     Trusted Firmware-M.  Historically, UniPhier BL was introduced to load BL1.
     BL1 was mandatory at that time because BL2 executes at BL1-S.  With a
     special mode, BL2_AT_EL3 supported, BL2 is now able to execute at EL3,
     allowing to skip BL1.  Then, the BL1 support for UniPhier platform was
     dropped from the code base of TF-A.


Why is this necessary?
----------------------

The UniPhier 64bit SoCs use TF-A as the secure world firmware.  It provides
various features with flexibility; however, the images become too large to be
loaded into the on-chip SRAM in some use-cases.

The Boot ROM of UniPhier SoCs loads 64KB [2] image from a non-volatile storage
into the on-chip SRAM.  This size is large enough for the boot flow without
firmware image authentication.

For real products, it is important to verify images to prevent any malformed
software from being run.  TF-A provides a standard firmware authentication
mechanism called Trusted Board Boot (TBB).  Unfortunately, if the TBB is
enabled, the TF-A BL2 exceeds the 64KB limit.

This loader has been introduced to solve the memory footprint problem.  The BL2
of TF-A is GZIP-compressed and appended to this loader.  The concatenated image
fits within the 64KB limit.  This loader initializes the DRAM and decompresses
the BL2 into the DRAM.  With this, there is no more image size problem on the
TF-A side since all BL images run in the DRAM.

[2]: Some SoCs can load 80KB, but the software implementation must be aligned
     to the lowest common denominator.


Boot flow
---------

1. The Boot ROM

  This is hard-wired ROM, so never corrupted.  It loads the UniPhier BL (with
  compressed-BL2 appended) into the on-chip SRAM.  If the SoC fuses are blown,
  the image is verified by the SoC's own method.

2. UniPhier BL (this loader)

  This runs in the on-chip SRAM.  After the minimum SoC initialization and DRAM
  setup, it decompresses the appended BL2 image into the DRAM, then jumps to
  the BL2 entry.

3. TF-A BL2 (at EL3)

  This runs in the DRAM.  It extracts more images from an image container called
  Firmware Image Package (FIP).  If TBB is enabled, they are all authenticated
  by the standard mechanism of TF-A.  After loading all the images, it jumps to
  the BL31 entry.

4. TF-A BL31 and more

  See TF-A documentation for further boot sequence.


Compile
-------

Make sure you have AArch64 toolchains.  Then,

    $ make CROSS_COMPILE=<toolchain-prefix>

Unless `CROSS_COMPILE` is specified from the command line or the environments,
`aarch64-linux-gnu-` is assumed.


Configuration
-------------

No explicit configuration is needed before the compile.  The default set of
config symbols are defined in `config.mk` and should work well.  If desired,
you can tweak some options such as `CONFIG_DEBUG`, `CONFIG_LOGLEVEL`, etc.


Build options
-------------

- `CROSS_COMPILE=<prefix>`

  Specify the prefix of the toolchains.

- `C=<level>`

  Turn on C code check.  The default checker is sparse (Semantic Parser for C).
  Currently, the valid value for `<level>` is `1`; all C files are checked,
  regardless of whether they are re-compiled or not.

- `O=<directory>`

  Specify the directory to store output files.  By default, all files generated
  during the build will be output in the source tree.  This option allows you
  to specify an alternate place for the output files.

- `V=<verbosity>`

  Set the build log verbosity.  The valid value is `0` or `1`.
  The default value is `0` (quiet).  The build log is printed in a short form.
  If it is set to `1` (verbose), the full log is displayed.


Environment variables
---------------------

- `CROSS_COMPILE`

  This can be set as an environment as well.

- `UNPH_CHECKSRC`

  Equivalent to specifying `C=<level>` from the command line.
  Setting `C=...` takes precedence over `UNPH_CHECKSRC`.

- `UNPH_OUTPUT`

  Equivalent to specifying `O=<directory>` from the command line.
  Setting `O=...` takes precedence over `UNPH_OUTPUT`.

- `UNPH_VERBOSE`

  Equivalent to specifying `V=<verbosity>` from the command line.
  Setting `V=...` takes precedence over `UNPH_VERBOSE`.


Output image
------------

Per-board images `bl_<board>.bin` are created.  Pick the appropriate one for
your board.


Generate final image
--------------------

To create the ready-to-burn image, the GZIP-compressed BL2 image `bl2.bin.gz`
is also needed.  Follow the document in TF-A to build this image.

Then, concatenate the two as follows:

    $ cat bl_<board>.bin bl2.bin.gz  >  <final-image>

Then, burn the `<final-image>` at the beginning of the non-volatile storage on
your board.  The storage is eMMC or NAND depending on your board specification.
