initypos, initxpos, resetangle = input("Starting Points and Angle: ").split()

print("arms::odom::reset({0, 0}, " + resetangle + ");")  # initial position reset

initypos = float(initypos)
initxpos = float(initxpos)

while True:
    newx, newy = input("Input Points: ").split()
    newxflt = float(newy)
    newyflt = float(newx)
    newx = newxflt - initxpos
    newy = newyflt - initypos
    newy *= -1
    newx = str(newx)
    newy = str(newy)
    print("arms::chassis::move({" + newx + ", " + newy + "}, 100);")