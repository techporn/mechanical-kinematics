import SchemDraw
import SchemDraw.elements as e
d = SchemDraw.Drawing()

d.add(e.DOT)
d.add(e.RES, label="$R[\Omega]$", d="down")
d.add(e.DOT)
d.add(e.LINE, d="right")

d.add(e.DOT_OPEN)
x = d.add(e.GAP, label="$x(t)[V]$", d="up", lblofst=-1.5)
d.labelI(x, arrowofst=-0.15)
d.add(e.DOT_OPEN)
d.add(e.LINE, d="left")

d.add(e.INDUCTOR, label="L[H]", d="left")
d.add(e.DOT_OPEN)
u = d.add(e.GAP, label="$u(t)[V]$", d="down", lblofst=-1.5)
d.labelI(u, arrowofst=-0.15)
d.add(e.DOT_OPEN)
d.add(e.LINE, d="right")

d.draw()
# d.save('testschematic.svg')
