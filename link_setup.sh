ip netns add node1
ip netns add node2
ip netns add node3
ip netns add memory_pool
ip link add veth_1 type veth peer name veth_sw1
ip link add veth_2 type veth peer name veth_sw2
ip link add veth_3 type veth peer name veth_sw3
ip link add veth_mp type veth peer name veth_4
ip link add ISP type bridge
ip link set veth_1 up
ip link set veth_2 up
ip link set veth_3 up
ip link set veth_4 up
ip link set veth_sw1 up
ip link set veth_sw2 up
ip link set veth_sw3 up
ip link set veth_mp up
ip link set veth_1 netns node1
ip link set veth_2 netns node2
ip link set veth_3 netns node3
ip link set veth_4 netns memory_pool
ip link set veth_sw1 master ISP
ip link set veth_sw2 master ISP
ip link set veth_sw3 master ISP
ip link set veth_mp master ISP
