# Rubik’s Cube Renderer

A real‑time, interactive **3×3 Rubik’s Cube** implemented with modern OpenGL. It supports per‑face coloring, smooth scene rotation/translation with the mouse, and layer rotations via keyboard (R/L/U/D/F/B) with adjustable step angle and direction.

> **Demo**: ![Uploading rubiks-cube-gif.gif…]()


---

## Features
- **3×3 cube assembled from 26/27 cubies** (center of the core is virtual).
- **Per‑face colors** driven in the fragment shader.
- **Smooth animations** for both scene and face turns.
- **Configurable step angle** per move with runtime controls.
- **Robust data structures** for transforms and face selection (see below).
- **Extensible hooks** ready for sequences of moves, scrambler (mixer), and solver integration.

---

## Controls

### Keyboard
- **Scene rotation**: `↑` `↓` `←` `→` (rotate whole scene around global X/Y)
- **Face rotations**: `R` `L` `U` `D` `F` `B` (90° clockwise by default)
- **Flip direction**: `Space` (CW ↔ CCW)
- **Adjust step angle**: `Z` (÷2), `A` (×2, capped at 180°)

### Mouse
- **Rotate cube**: *Left‑drag*  
  (left/right → global Y, up/down → global X)
- **Pan camera**: *Right‑drag*
- **Zoom**: *Scroll*

---

## How it works

### Rendering & Transforms
- **Movable‑style transform stack** to accumulate per‑object transforms.
- Each cubie is a draw call with its own model matrix; scene rotation applies an additional parent transform.

### Face Selection Logic
- **Logical cubie index grid** (x, y, z ∈ {−1, 0, +1}) defines positions.
- For a given face (e.g., `R`), we select cubies whose coordinate matches that face’s fixed index (e.g., `x = +1`).
- Selected cubies receive an incremental rotation about the appropriate world axis until the target step angle completes; then indices and transforms are **re‑indexed/rounded** to remain numerically stable.

---

## Build & Run

> The project uses standard OpenGL tooling. Below are common options; adapt as needed for your environment.

### Dependencies
- OpenGL 3.3+
- **GLFW** (window/input)
- **GLAD** (loader)
- **GLM** (math)
- *(Optional)* **stb_image.h** (if you add textures or screenshots)

### CMake (recommended)
```bash
mkdir -p build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release
./RubiksCubeRenderer
```

### Manual compile (Linux/macOS example)
```bash
g++ -std=c++17 -O2 -o RubiksCubeRenderer \
  src/main.cpp src/cube.cpp src/shader.cpp \
  -lglfw -framework OpenGL  # or -lGL on Linux
```
> On Windows/MinGW or MSVC, link the corresponding GLFW/GLAD libs and ensure GLAD sources are compiled into the project.

---

## Project Structure (example)
```
.
├── src/
│   ├── main.cpp           # app entry, input handling, render loop
│   ├── cube.cpp/.hpp      # cubie structs, face selection, rotations
│   ├── shader.cpp/.hpp    # utility to compile/link shaders
│   └── utils.hpp          # math helpers, rounding/reindex helpers
├── shaders/
│   ├── cube.vert          # positions, normals, instance transforms
│   └── cube.frag          # per‑face coloring
├── assets/                # screenshots, future textures
├── CMakeLists.txt
└── README.md
```

---

## Implementation Notes
- **Numerical stability**: after completing a face turn, snap cubie transforms to the nearest 90° and update logical indices to avoid drift.
- **Animation**: apply small per‑frame deltas until `stepAngle` is reached; the `Z/A` keys adjust this `stepAngle` live.
- **Coordinate system**: face turns are defined about **global axes** to simplify interaction with scene rotation.
- **Shader coloring**: per‑face colors can be passed as uniforms or derived from a per‑cubie face‑ID attribute.

---

## Roadmap
- [ ] Move sequence player (alg notation parser)
- [ ] **Scrambler (mixer)**
- [ ] **Solver** integration (e.g., Kociemba two‑phase or CFOP layer‑by‑layer)
- [ ] Save/Load cube state (JSON)
- [ ] Screenshot/GIF capture helper

---

## FAQ
**Why 26/27 cubies?**  
The physical cube has 26 visible cubies; the central core is internal/virtual. In code you may keep a virtual center for indexing.

**Clockwise relative to what?**  
Clockwise is defined looking **into** the face from outside the cube, using standard cube notation.

---

## License
MIT (unless you choose otherwise). See `LICENSE`.

## Acknowledgements
- GLFW, GLAD, GLM, and stb by their respective authors.
- Thanks to the open‑source graphics community for patterns and inspiration.

