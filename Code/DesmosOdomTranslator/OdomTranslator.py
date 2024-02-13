initypos, initxpos, resetangle = input("Starting Points and Angle: ").split()  # Take an input for the initial points

print("arms::odom::reset({0, 0}, " + resetangle + ");")  # Output initial position reset

initypos = float(initypos)  # Converts input into a float
initxpos = float(initxpos)  # Converts input into a float

while True:
    newx, newy = input("Input Points: ").split()  # Takes input for point
    newxflt = float(newy)  # Converts Y direction into X direction
    newyflt = float(newx)  # Converts X direction into Y direction
    newx = newxflt - initxpos  # Makes X position relative to 0, 0 starting position
    newy = newyflt - initypos  # Makes Y position relative to 0, 0 starting position
    newy *= -1  # Gives Y direction correct sign
    newx = str(newx)  # Converts X position into string for outputting
    newy = str(newy)  # Converts Y position into string for outputting
    print("arms::chassis::move({" + newx + ", " + newy + "}, 100);")  # Output movement command
