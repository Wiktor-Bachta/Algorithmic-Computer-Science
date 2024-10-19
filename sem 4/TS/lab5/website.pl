use HTTP::Daemon;
use HTTP::Status;  

my $d = HTTP::Daemon->new || die;
print "Please contact me at: ", $d->url, "\n";


while (my $c = $d->accept) {
    while (my $r = $c->get_request) {
        if ($r->method eq 'GET') {
            $path = $r->uri->path;
           
            if (index($path, "/koty") == 0) {
                $real_path = "./website/koty";
                if (index($path, "/cat") == 5) {
                    $real_path = $real_path . "/zdjecia/" . substr($path, 6) . ".html";
                    $c->send_file_response($real_path);
                }
                elsif (length($path) == 5) {
                    $real_path = $real_path . "/koty.html";
                    $c->send_file_response($real_path);
                }
                else {
                    $c->send_error(RC_FORBIDDEN);
                }
            }
            elsif (index($path, "/psy") == 0 && length($path) == 4) {
                $c->send_file_response("./website/psy/psy.html");
            }
            elsif (length($path) == 1) {
                $c->send_file_response("./website/index.html");
            }
            else {
                $c->send_error(RC_FORBIDDEN);
            }
        }
        else {
            $c->send_error(RC_FORBIDDEN);
        }
    }
    $c->close;
    undef($c);
}
