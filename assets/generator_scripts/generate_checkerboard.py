#!/usr/bin/env python3
"""Generate a 2048x2048 PNG with a 20x20 checkerboard pattern of tan and light gray squares."""

from PIL import Image

# Image dimensions
IMAGE_SIZE = 2048
GRID_SIZE = 20
SQUARE_SIZE = IMAGE_SIZE // GRID_SIZE  # 102.4, but will use 102 per square

# Colors: tan and light gray
TAN = (210, 180, 140)
LIGHT_GRAY = (170, 170, 170)

def generate_checkerboard():
    """Generate a checkerboard pattern image."""
    img = Image.new('RGB', (IMAGE_SIZE, IMAGE_SIZE))
    pixels = img.load()
    
    for y in range(IMAGE_SIZE):
        for x in range(IMAGE_SIZE):
            # Determine which square we're in
            square_x = x // SQUARE_SIZE
            square_y = y // SQUARE_SIZE
            
            # Checkerboard pattern: alternate colors
            if (square_x + square_y) % 2 == 0:
                pixels[x, y] = TAN
            else:
                pixels[x, y] = LIGHT_GRAY
    
    return img

if __name__ == "__main__":
    print("Generating 2048x2048 checkerboard pattern...")
    image = generate_checkerboard()
    output_file = "checkerboard.png"
    image.save(output_file)
    print(f"Saved to {output_file}")
