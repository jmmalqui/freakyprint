# freakyprint
Print out stuff to the console in a *freaky* way.

## How to

Run the following commands to build the project.
### Using Make
```bash
make
```
### Using the Meson Build System
Make sure to have meson installed on your system, see https://mesonbuild.com/Getting-meson.html for more details.
```bash
meson setup build
```
Then, compile the program from within the ```build``` folder.
```bash
meson compile
```
## Running freakyprint
Once the binary is built, go to the `build` directory and run:
```bash
./freakyprint [your_string]
```

