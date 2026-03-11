# MakeMKV 1.18.3 for Linux

> Unofficial mirror of the official build and installation instructions posted by **mike admin** on the [MakeMKV Linux forum](https://forum.makemkv.com/forum/viewtopic.php?f=3&t=224).  
> For the latest version information, see the [MakeMKV changelog thread](https://www.makemkv.com/forum2/viewtopic.php?f=5&t=1054).

---

## Table of Contents

- [About](#about)
- [Step 1 — Download Both Packages](#step-1--download-both-packages)
- [Step 2 — Install Prerequisites](#step-2--install-prerequisites)
- [Step 3 — Build and Install](#step-3--build-and-install)
  - [makemkv-oss](#makemkv-oss)
  - [makemkv-bin](#makemkv-bin)
- [Optional: Building with Latest libavcodec](#optional-building-with-latest-libavcodec)
- [License](#license)

---

## About

The Linux release of MakeMKV includes full source code for:

| Component | Description |
|---|---|
| MakeMKV GUI | Graphical user interface |
| `libmakemkv` | Multiplexer library |
| `libdriveio` | MMC drive interrogation library |

Two packages must be downloaded and built:

| Package | Type |
|---|---|
| `makemkv-oss-1.18.3.tar.gz` | Open-source component (source) |
| `makemkv-bin-1.18.3.tar.gz` | Proprietary binary component |

The application installs to **`/usr/bin/makemkv`**.

---

## Step 1 — Download Both Packages

Download both the binary and source packages directly from the official MakeMKV download page:

```
https://www.makemkv.com/download/makemkv-oss-1.18.3.tar.gz
https://www.makemkv.com/download/makemkv-bin-1.18.3.tar.gz
```

Unpack both archives before proceeding.

---

## Step 2 — Install Prerequisites

You will need the GNU compiler and linker, plus header and library files for:

- `glibc`
- `openssl` (≥ 0.9.8)
- `zlib`
- `expat`
- `libavcodec`
- `Qt5`

### Debian-based systems (Ubuntu, Linux Mint, etc.)

```bash
sudo apt-get install build-essential pkg-config libc6-dev libssl-dev \
  libexpat1-dev libavcodec-dev libgl1-mesa-dev qtbase5-dev zlib1g-dev
```

---

## Step 3 — Build and Install

Starting from the unpacked source package, follow these steps **in order**.

### makemkv-oss

```bash
./configure
make
sudo make install
```

### makemkv-bin

```bash
make
sudo make install
```

The application will be installed as `/usr/bin/makemkv`.

---

## Optional: Building with Latest libavcodec

Starting with version **1.8.6**, MakeMKV links directly to `libavcodec`.

> Most distributions ship a very outdated version of `libavcodec` (either from the FFmpeg or libav projects).

You will need to compile a recent **FFmpeg (≥ 2.0)** if you require any of the following:

- A **FLAC encoder** that handles 24-bit audio
- An **AAC encoder** (requires `libfdk-aac` enabled in FFmpeg)
- **DTS-HD decoding** — handled by FFmpeg since MakeMKV version **1.12.1**

### 1. Download FFmpeg

Get the FFmpeg source tarball from [https://ffmpeg.org/download.html](https://ffmpeg.org/download.html).

### 2. Configure and Build FFmpeg

Standard build:

```bash
./configure --prefix=/tmp/ffmpeg --enable-static --disable-shared --enable-pic
```

Or with `libfdk-aac` support (for AAC encoding):

```bash
./configure --prefix=/tmp/ffmpeg --enable-static --disable-shared --enable-pic --enable-libfdk-aac
```

Then install:

```bash
make install
```

### 3. Configure and Build makemkv-oss Against the New FFmpeg

```bash
PKG_CONFIG_PATH=/tmp/ffmpeg/lib/pkgconfig ./configure
make
sudo make install
```

### 4. Remove Temporary FFmpeg Files

```bash
rm -rf /tmp/ffmpeg
```

---

## License

This repository contains documentation mirroring the official MakeMKV Linux forum post only.

**MakeMKV** is proprietary software © GuinpinSoft inc., subject to the [MakeMKV End User License Agreement](https://www.makemkv.com/eula.html).

The `makemkv-oss` component is licensed under the **GNU General Public License v2 (GPL-2.0)** and the **Mozilla Public License 1.1 (MPL-1.1)**. See [LICENSE](LICENSE) for the terms covering the documentation in this repository.
