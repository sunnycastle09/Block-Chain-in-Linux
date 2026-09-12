ip netns add node1
ip netns add node2
ip netns add node3
ip link add veth_1 type veth peer veth_gw1
ip link add veth_2 type veth peer veth_gw2
ip link add veth_3 type veth peer veth_gw3
ip link add ISP type bridge
ip link set veth_gw1 master ISP
ip link set veth_gw2 master ISP
ip link set veth_gw3 master ISP
ip link set veth_1 netns node1
ip link set veth_2 netns node2
ip link set veth_3 netns node3
ip netns exec node1 ip link set veth_1 up
ip netns exec node2 ip link set veth_2 up
ip netns exec node3 ip link set veth_3 up
ip link set ISP up
ip link set veth_gw1 up
ip link set veth_gw2 up
ip link set veth_gw3 up
ip addr add 10.0.0.4/24 dev ISP
ip netns exec node1 ip addr add 10.0.0.1/24 dev veth_1
ip netns exec node2 ip addr add 10.0.0.2/24 dev veth_2
ip netns exec node3 ip addr add 10.0.0.3/24 dev veth_3
ip link show
ip netns exec node1 ip link show
ip netns exec node2 ip link show
ip netns exec node3 ip link show
