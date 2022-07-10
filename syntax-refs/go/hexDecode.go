package refs

import (
	"encoding/hex"
	"fmt"
	"log"
)

func HexDecodeRef() {
	a := "06082A8648CE3D030107"
	bin, err := hex.DecodeString(a)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(bin)
}