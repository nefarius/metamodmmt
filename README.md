# metamodmmt
Proxy DLL for Metamod for Half-Life 1 enabling Windows high-resolution timers

## About

> ### FPS Boost
> Unfortunately, both of these servers will not achieve these FPS settings on a Win32 platform without one tweak. In order for the server to get service from the operating system, there must be a high-resolution timer running. Normally, the operating system runs a low resolution timer that is only good for a max of maybe 100FPS.
> 
> Running Media Player (you need not play a file, just have it sitting there open) will force the operating system to use a high-res times that will give your server the capability of running up to 1000FPS. Media Player requires about 5MB while in idle, so it offers relatively low overhead for this improvement. You can also run a Macromedia SWF file in Internet Explore and it will do the same thing.

-- [Quoted from VALVe](https://support.steampowered.com/kb_article.php?ref=5386-HMJI-5162)

## Sources
 * [High tickrate and rate SRCDS FAQ](http://forums.srcds.com/viewtopic/1094)
 * [timeBeginPeriod function](https://msdn.microsoft.com/en-us/library/vs/alm/dd757624(v=vs.85).aspx?f=255&MSPPError=-2147217396)
 * [Metamod](http://metamod.org/)
 * [Metamod Half-Life Utility mod](https://sourceforge.net/projects/metamod/?source=typ_redirect)
 * [Optimizing a Dedicated Server](https://support.steampowered.com/kb_article.php?ref=5386-HMJI-5162)
 * [Fork of Metamod for Half-Life 1](https://github.com/alliedmodders/metamod-hl1)
 * [TimerTool](https://github.com/tebjan/TimerTool)
