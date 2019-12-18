# Midas
Dota 2 left-hand Ergodox keymap

> Preserved through unknown magical means, \
> the Hand of Midas is a weapon of greed, \
> sacrificing animals to line the owner's pockets.

## Prerequisites

- docker

## Notes

This keymap is made for an Ergodox PCB from [Falbatech].
It's the right side PCB, so [QMK's Swap Hands] functionality is used
to flip the layout and avoid having to awkwardly mirror it manually.

## Build

```console
$ make
```

## Flash

Put keyboard μC into programming mode, either by pressing the push button
on the board itself, or by sending the `RESET` keycode.

```console
$ make install
```

[Falbatech]: https://falba.tech
[QMK's Swap Hands]: https://beta.docs.qmk.fm/features/feature_swap_hands
