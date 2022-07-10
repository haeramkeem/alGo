package refs

import (
	"fmt"

	"github.com/spf13/pflag"
)

func PFlagRef() {
	b := pflag.Bool("boolean", false, "holymoly")
	s := pflag.String("string", "default", "guacamole")

	pflag.Parse()

	fmt.Println("string has value ", *s)
	fmt.Println("bool has value ", *b)
}
