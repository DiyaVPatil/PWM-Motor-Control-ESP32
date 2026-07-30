## PCB Design
Designed entirely using KiCad.
The design process included:

- Schematic capture
- Component selection
- Custom symbol and footprint creation 
- ERC verification
- PCB layout
- DRC verification
- Gerber & BOM generation

## Testing
The completed board was thoroughly tested using:

- Variable PWM duty cycles
- Battery operation
- Motor startup behavior
- Thermal observation
- Electrical verification 
- Functional verification
  
## Why PWM?
Pulse Width Modulation (PWM) allows motor speed to be controlled efficiently by rapidly switching the MOSFET between fully ON and fully OFF states,
with the advantage of high-efficiency motor control, reduced thermal losses, low power dissipation, extended battery runtime and smooth speed adjustment. 
This makes PWM the gold standard for Electronic speed control (ESC), hence why it's such a powerful tool when designing specifically, consumer electronics.

## Challenges
The biggest challenge was debugging hardware that appeared to have multiple faults, which ultimately traced back to a single cold solder joint.
After hours of systematically checking connections, measuring voltages, and testing components,
I learned firsthand how a small physical fault can lead to extensive debugging in hardware development.

The project also required careful power management, MOSFET selection, flyback protection,
and the transition from a hand-wired perfboard prototype to a verified KiCad PCB.
