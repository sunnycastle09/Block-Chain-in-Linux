ip netns add node1
ip netns add node2
ip netns add node3
ip netns add User
ip netns add DNSnode
ip link add veth_1 type veth peer veth_gw1
ip link add veth_2 type veth peer veth_gw2
ip link add veth_3 type veth peer veth_gw3
ip link add veth_U type veth peer veth_gw4
ip link add DNS type veth peer veth_gw5
ip link add ISP type bridge
ip link set veth_gw1 master ISP
ip link set veth_gw2 master ISP
ip link set veth_gw3 master ISP
ip link set veth_gw4 master ISP
ip link set veth_gw5 master ISP
ip link set veth_1 netns node1
ip link set veth_2 netns node2
ip link set veth_3 netns node3
ip link set veth_U netns User
ip link set DNS netns DNSnode
ip netns exec node1 ip link set veth_1 up
ip netns exec node2 ip link set veth_2 up
ip netns exec node3 ip link set veth_3 up
ip netns exec User ip link set veth_U up
ip netns exec DNSnode ip link set DNS up
ip link set ISP up
ip link set veth_gw1 up
ip link set veth_gw2 up
ip link set veth_gw3 up
ip link set veth_gw4 up
ip link set veth_gw5 up
ip link show
ip netns exec node1 ip link show
ip netns exec node2 ip link show
ip netns exec node3 ip link show
ip netns exec User ip link show
ip netns exec DNSnode ip link show
